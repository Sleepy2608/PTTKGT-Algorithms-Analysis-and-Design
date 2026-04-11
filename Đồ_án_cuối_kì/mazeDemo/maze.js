const N = 41;
let grid = [];
let start, end;
let customers = [];
let allRoutes = [];

const colors = ["red","blue","green","purple","orange","cyan"];

const canvas = document.getElementById("mazeCanvas");
const ctx = canvas.getContext("2d");

// ================= CLICK =================
canvas.addEventListener("click", e => {
    const rect = canvas.getBoundingClientRect();
    const size = canvas.width / N;

    let y = Math.floor((e.clientX - rect.left) / size);
    let x = Math.floor((e.clientY - rect.top) / size);

    let p = ensureValidPoint(x,y);
    customers.push(p);

    draw();
});

// ================= MAZE =================
function generateMaze(diff="medium"){
    grid = Array.from({length:N}, ()=>Array(N).fill(1));

    function carve(x,y){
        let dirs=[[2,0],[-2,0],[0,2],[0,-2]].sort(()=>Math.random()-0.5);

        for(let [dx,dy] of dirs){
            let nx=x+dx, ny=y+dy;
            if(nx>0&&ny>0&&nx<N-1&&ny<N-1&&grid[nx][ny]){
                grid[nx][ny]=0;
                grid[x+dx/2][y+dy/2]=0;
                carve(nx,ny);
            }
        }
    }

    grid[1][1]=0;
    carve(1,1);

    let breakChance = diff==="easy"?0.25: diff==="hard"?0.05:0.15;

    for(let i=1;i<N-1;i++)
        for(let j=1;j<N-1;j++)
            if(grid[i][j] && Math.random()<breakChance)
                grid[i][j]=0;

    start={x:1,y:1};
    end={x:N-2,y:N-2};

    customers=[];
    allRoutes=[];
    draw();
}

// ================= DRAW =================
function draw(path=[], visited=[]){
    const s = canvas.width/N;

    for(let i=0;i<N;i++)
        for(let j=0;j<N;j++){
            ctx.fillStyle = grid[i][j]?"#111":"#eee";
            ctx.fillRect(j*s,i*s,s,s);
        }

    ctx.fillStyle="yellow";
    visited.forEach(p=>ctx.fillRect(p.y*s,p.x*s,s,s));

    ctx.fillStyle="red";
    path.forEach(p=>ctx.fillRect(p.y*s,p.x*s,s,s));

    ctx.fillStyle="green";
    ctx.fillRect(start.y*s,start.x*s,s,s);

    ctx.fillStyle="blue";
    ctx.fillRect(end.y*s,end.x*s,s,s);

    ctx.fillStyle="orange";
    customers.forEach((c,i)=>{
        ctx.fillRect(c.y*s,c.x*s,s,s);
        ctx.fillStyle="black";
        ctx.fillText(i+1,c.y*s+4,c.x*s+14);
        ctx.fillStyle="orange";
    });
}

// ================= BFS PATH =================
function bfsPath(a,b){
    let q=[a];
    let vis=Array.from({length:N},()=>Array(N).fill(false));
    let par=Array.from({length:N},()=>Array(N).fill(null));

    vis[a.x][a.y]=true;

    while(q.length){
        let cur=q.shift();
        if(cur.x===b.x&&cur.y===b.y) break;

        for(let [dx,dy] of [[1,0],[-1,0],[0,1],[0,-1]]){
            let nx=cur.x+dx, ny=cur.y+dy;
            if(nx>=0&&ny>=0&&nx<N&&ny<N&&!vis[nx][ny]&&!grid[nx][ny]){
                vis[nx][ny]=true;
                par[nx][ny]=cur;
                q.push({x:nx,y:ny});
            }
        }
    }

    let path=[], cur=b;
    while(cur){ path.push(cur); cur=par[cur.x][cur.y]; }
    return path.reverse();
}

// ================= BFS ANIMATION =================
async function bfsAnimated(){
    let visited = Array.from({length:N},()=>Array(N).fill(false));
    let parent = Array.from({length:N},()=>Array(N).fill(null));

    let q=[start];
    visited[start.x][start.y]=true;

    let visitedList=[];

    while(q.length){
        let cur=q.shift();
        visitedList.push(cur);

        draw([], visitedList);
        await sleep(10);

        if(cur.x===end.x&&cur.y===end.y) break;

        for(let [dx,dy] of [[1,0],[-1,0],[0,1],[0,-1]]){
            let nx=cur.x+dx, ny=cur.y+dy;

            if(nx>=0&&ny>=0&&nx<N&&ny<N&&!visited[nx][ny]&&!grid[nx][ny]){
                visited[nx][ny]=true;
                parent[nx][ny]=cur;
                q.push({x:nx,y:ny});
            }
        }
    }

    return reconstruct(parent);
}

// ================= DFS =================
function dfs(){
    let vis=Array.from({length:N},()=>Array(N).fill(false));
    let path=[], found=false;

    function go(x,y){
        if(found) return;
        vis[x][y]=true;
        path.push({x,y});

        if(x===end.x&&y===end.y){ found=true; return; }

        for(let [dx,dy] of [[1,0],[-1,0],[0,1],[0,-1]]){
            let nx=x+dx,ny=y+dy;
            if(nx>=0&&ny>=0&&nx<N&&ny<N&&!vis[nx][ny]&&!grid[nx][ny])
                go(nx,ny);
        }

        if(!found) path.pop();
    }

    go(start.x,start.y);
    return path;
}

// ================= A* ANIMATION =================
async function astarAnimated(){
    let open=[{...start,g:0,f:0}];
    let vis=Array.from({length:N},()=>Array(N).fill(false));
    let par=Array.from({length:N},()=>Array(N).fill(null));

    const h=(x,y)=>Math.abs(x-end.x)+Math.abs(y-end.y);

    let visitedList=[];

    while(open.length){
        open.sort((a,b)=>a.f-b.f);
        let cur=open.shift();

        if(vis[cur.x][cur.y]) continue;
        vis[cur.x][cur.y]=true;

        visitedList.push(cur);
        draw([], visitedList);
        await sleep(10);

        if(cur.x===end.x&&cur.y===end.y) break;

        for(let [dx,dy] of [[1,0],[-1,0],[0,1],[0,-1]]){
            let nx=cur.x+dx, ny=cur.y+dy;
            if(nx>=0&&ny>=0&&nx<N&&ny<N&&!vis[nx][ny]&&!grid[nx][ny]){
                par[nx][ny]=cur;
                open.push({x:nx,y:ny,g:cur.g+1,f:cur.g+1+h(nx,ny)});
            }
        }
    }

    return reconstruct(par);
}

// ================= RECONSTRUCT =================
function reconstruct(parent){
    let path=[], cur=end;
    while(cur){ path.push(cur); cur=parent[cur.x][cur.y]; }
    return path.reverse();
}

// ================= VRP =================
function solveVRP(){
    if(customers.length === 0) return [[end]];

    let routes = customers.map(c => [c]);

    let changed = true;

    while(changed){
        changed = false;

        for(let i=0;i<routes.length;i++){
            for(let j=0;j<routes.length;j++){
                if(i===j) continue;

                let A = routes[i][routes[i].length-1];
                let B = routes[j][0];

                let dDepotB = bfsPath(start,B).length;
                let dAtoB   = bfsPath(A,B).length;

                // 🔥 CORE LOGIC CỦA BẠN
                if(dAtoB < dDepotB){
                    routes[i] = routes[i].concat(routes[j]);
                    routes.splice(j,1);

                    changed = true;
                    break;
                }
            }
            if(changed) break;
        }
    }

    return routes;
}

// ================= RUN VRP =================
async function runVRP(){
    allRoutes=[];

    if(customers.length===0){
        customers=[end];
    }

    let routes = solveVRP();

    routes = removeOverlappingRoutes(routes);

    showResult(routes);

    for(let r=0;r<routes.length;r++){
        let fullPath = buildFullPath(routes[r]);

        allRoutes.push({
            path: fullPath,
            color: colors[r % colors.length]
        });
    }

    await animateAllRoutes();
}

// ================= MULTI ANIMATION =================
function drawAllRoutes(step){
    const s = canvas.width / N;

    // ⚠️ chỉ vẽ nền 1 lần mỗi frame
    draw();

    allRoutes.forEach(({path, color}) => {
        ctx.strokeStyle = color;
        ctx.lineWidth = 3;
        ctx.lineCap = "round";
        ctx.lineJoin = "round";
        ctx.beginPath();

        for(let i=0;i<path.length;i++){
            if(i > step) break;

            let p = path[i];
            let x = p.y*s + s/2;
            let y = p.x*s + s/2;

            if(i === 0) ctx.moveTo(x,y);
            else ctx.lineTo(x,y);
        }

        ctx.stroke(); // 👉 vẽ full path tới step
    });
}

async function animateAllRoutes(){
    let maxLen = Math.max(...allRoutes.map(r => r.path.length));

    for(let step=0;step<maxLen;step++){
        drawAllRoutes(step);
        await sleep(25);
    }
}

function removeOverlappingRoutes(routes){
    let finalRoutes = [];

    for(let i=0;i<routes.length;i++){
        let keep = true;

        for(let j=0;j<routes.length;j++){
            if(i===j) continue;

            let pathI = buildFullPath(routes[i]);
            let pathJ = buildFullPath(routes[j]);

            let setJ = new Set(pathJ.map(p=>p.x+"-"+p.y));

            // nếu path I bị path J cover
            let covered = pathI.every(p => setJ.has(p.x+"-"+p.y));

            if(covered){
                keep = false;
                break;
            }
        }

        if(keep) finalRoutes.push(routes[i]);
    }

    return finalRoutes;
}

function removeOverlappingRoutes(routes){
    let finalRoutes = [];

    for(let i=0;i<routes.length;i++){
        let pathI = buildFullPath(routes[i]);

        let dominated = false;

        for(let j=0;j<routes.length;j++){
            if(i===j) continue;

            let pathJ = buildFullPath(routes[j]);

            // nếu J chứa hết I → I bị đè
            let setJ = new Set(pathJ.map(p=>p.x+"-"+p.y));

            if(pathI.every(p => setJ.has(p.x+"-"+p.y))){
                dominated = true;
                break;
            }
        }

        if(!dominated) finalRoutes.push(routes[i]);
    }

    return finalRoutes;
}

// ================= SOLVE =================
async function solveMazeLocal(type){
    let path;

    if(type==="bfs") path=await bfsAnimated();
    else if(type==="dfs") path=dfs();
    else path=await astarAnimated();

    await animate(path);
}

// ================= ANIMATION =================
async function animate(path, color="red"){
    const s = canvas.width/N;

    // 👉 vẽ nền 1 lần
    draw();

    ctx.strokeStyle = color;
    ctx.lineWidth = 3;
    ctx.beginPath();

    for(let i=0;i<path.length;i++){
        let p = path[i];
        let x = p.y*s + s/2;
        let y = p.x*s + s/2;

        if(i===0) ctx.moveTo(x,y);
        else ctx.lineTo(x,y);

        ctx.stroke(); // vẽ dần từng đoạn

        await sleep(20);
    }
}

function sleep(ms){
    return new Promise(r=>setTimeout(r,ms));
}

// ================= UTILS =================
function clearCustomers(){
    customers=[];
    draw();
}

function ensureValidPoint(x,y){
    if(!grid[x][y]) return {x,y};

    let q=[{x,y}], vis=Array.from({length:N},()=>Array(N).fill(false));
    vis[x][y]=true;

    while(q.length){
        let cur=q.shift();
        if(!grid[cur.x][cur.y]) return cur;

        for(let [dx,dy] of [[1,0],[-1,0],[0,1],[0,-1]]){
            let nx=cur.x+dx,ny=cur.y+dy;
            if(nx>=0&&ny>=0&&nx<N&&ny<N&&!vis[nx][ny]){
                vis[nx][ny]=true;
                q.push({x:nx,y:ny});
            }
        }
    }
}

//xuất kq
function showResult(routes){
    const resultDiv = document.getElementById("result");
    resultDiv.innerHTML = "";

    routes.forEach((route, idx) => {
        let text = `Shipper ${idx+1} (màu ${colors[idx % colors.length]}): Kho`;

        route.forEach(p => {
            let index = customers.findIndex(c => c.x===p.x && c.y===p.y);
            text += ` → Điểm ${index+1}`;
        });

        let p = document.createElement("p");
        p.textContent = text;
        p.style.color = colors[idx % colors.length];

        resultDiv.appendChild(p);
    });
}

//build patch
function buildFullPath(route){
    let fullPath = [];
    let prev = start;

    for(let p of route){
        let seg = bfsPath(prev, p);
        if(fullPath.length > 0) seg.shift();
        fullPath = fullPath.concat(seg);
        prev = p;
    }

    //vẽ đường quay về lại kho (0, 0)
    let returnToDepot = false; //true = mở quay về, false = tắt quay về
    if(returnToDepot){
        let back = bfsPath(prev, start);
        back.shift();
        fullPath = fullPath.concat(back);
    }

    return fullPath;
}

// ================= INIT =================
generateMaze();
