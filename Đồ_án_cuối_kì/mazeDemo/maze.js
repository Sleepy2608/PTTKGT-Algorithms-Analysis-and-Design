const N = 31;
let grid = [];
let start = {x:0, y:0};
let end = {x:N-1, y:N-1};

const canvas = document.getElementById("mazeCanvas");
const ctx = canvas.getContext("2d");

// ================= MAZE GENERATION (DFS CARVE) =================
function generateMaze(difficulty = "medium") {
    grid = Array.from({length:N}, () => Array(N).fill(1));

    function carve(x, y) {
        let dirs = [[2,0],[-2,0],[0,2],[0,-2]];
        dirs.sort(() => Math.random() - 0.5);

        for (let [dx, dy] of dirs) {
            let nx = x + dx;
            let ny = y + dy;

            if (nx > 0 && ny > 0 && nx < N-1 && ny < N-1 && grid[nx][ny] === 1) {
                grid[nx][ny] = 0;
                grid[x + dx/2][y + dy/2] = 0;
                carve(nx, ny);
            }
        }
    }

    // bắt đầu từ (1,1)
    grid[1][1] = 0;
    carve(1,1);

    // ===== TẠO NHIỀU ĐƯỜNG (PHÁ TƯỜNG) =====
    let breakChance = 0.1; // mặc định

    if (difficulty === "easy") breakChance = 0.25;
    if (difficulty === "medium") breakChance = 0.15;
    if (difficulty === "hard") breakChance = 0.05;

    for (let i = 1; i < N-1; i++) {
        for (let j = 1; j < N-1; j++) {
            if (grid[i][j] === 1 && Math.random() < breakChance) {
                grid[i][j] = 0;
            }
        }
    }

    // start & end
    start = {x:1, y:1};
    end = {x:N-2, y:N-2};
    grid[end.x][end.y] = 0;

    draw();
}

// ================= DRAW =================
function draw(path=[], visited=[]) {
    const size = canvas.width / N;

    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {

            // tường
            if (grid[i][j] === 1) ctx.fillStyle = "#111";

            // đường đi
            else ctx.fillStyle = "#f0f0f0";

            ctx.fillRect(j*size, i*size, size, size);
        }
    }

    // visited (màu vàng)
    ctx.fillStyle = "yellow";
    visited.forEach(p => {
        ctx.fillRect(p.y*size, p.x*size, size, size);
    });

    // path (màu đỏ)
    ctx.fillStyle = "red";
    path.forEach(p => {
        ctx.fillRect(p.y*size, p.x*size, size, size);
    });

    // start (xanh lá)
    ctx.fillStyle = "green";
    ctx.fillRect(start.y*size, start.x*size, size, size);

    // end (xanh dương)
    ctx.fillStyle = "blue";
    ctx.fillRect(end.y*size, end.x*size, size, size);
}

// ================= BFS (ANIMATION) =================
async function bfsAnimated() {
    let visited = Array.from({length:N}, () => Array(N).fill(false));
    let parent = Array.from({length:N}, () => Array(N).fill(null));

    let queue = [start];
    visited[start.x][start.y] = true;

    let dirs = [[1,0],[-1,0],[0,1],[0,-1]];
    let visitedList = [];

    while (queue.length) {
        let cur = queue.shift();
        visitedList.push(cur);

        draw([], visitedList);
        await sleep(10);

        if (cur.x === end.x && cur.y === end.y) break;

        for (let [dx,dy] of dirs) {
            let nx = cur.x + dx;
            let ny = cur.y + dy;

            if (nx>=0 && ny>=0 && nx<N && ny<N &&
                !visited[nx][ny] && grid[nx][ny]===0) {

                visited[nx][ny] = true;
                parent[nx][ny] = cur;
                queue.push({x:nx,y:ny});
            }
        }
    }

    return reconstruct(parent);
}

// ================= DFS =================
function dfs() {
    let visited = Array.from({length:N}, () => Array(N).fill(false));
    let path = [];
    let found = false;

    function backtrack(x,y) {
        if (found) return;

        visited[x][y] = true;
        path.push({x,y});

        if (x===end.x && y===end.y) {
            found = true;
            return;
        }

        let dirs = [[1,0],[-1,0],[0,1],[0,-1]];

        for (let [dx,dy] of dirs) {
            let nx = x+dx, ny = y+dy;
            if (nx>=0 && ny>=0 && nx<N && ny<N &&
                !visited[nx][ny] && grid[nx][ny]===0) {
                backtrack(nx,ny);
            }
        }

        if (!found) path.pop();
    }

    backtrack(start.x,start.y);
    return path;
}

// ================= A* =================
function astar() {
    let open = [];
    let visited = Array.from({length:N}, () => Array(N).fill(false));
    let parent = Array.from({length:N}, () => Array(N).fill(null));

    function h(x,y){
        return Math.abs(x-end.x)+Math.abs(y-end.y);
    }

    open.push({x:start.x,y:start.y,g:0,f:h(start.x,start.y)});

    while(open.length){
        open.sort((a,b)=>a.f-b.f);
        let cur = open.shift();

        if(visited[cur.x][cur.y]) continue;
        visited[cur.x][cur.y]=true;

        if(cur.x===end.x && cur.y===end.y) break;

        let dirs=[[1,0],[-1,0],[0,1],[0,-1]];

        for(let [dx,dy] of dirs){
            let nx=cur.x+dx, ny=cur.y+dy;

            if(nx>=0&&ny>=0&&nx<N&&ny<N &&
               !visited[nx][ny] && grid[nx][ny]===0){

                parent[nx][ny]=cur;

                open.push({
                    x:nx,
                    y:ny,
                    g:cur.g+1,
                    f:cur.g+1+h(nx,ny)
                });
            }
        }
    }

    return reconstruct(parent);
}

// ================= RECONSTRUCT =================
function reconstruct(parent){
    let path=[];
    let cur=end;

    while(cur){
        path.push(cur);
        cur=parent[cur.x][cur.y];
    }

    return path.reverse();
}

// ================= ANIMATION =================
async function animatePath(path) {
    for (let i = 0; i < path.length; i++) {
        draw(path.slice(0, i+1));
        await sleep(40);
    }
}

function sleep(ms){
    return new Promise(r => setTimeout(r, ms));
}

// ================= CONTROLLER =================
async function solveMazeLocal(type){
    let path;

    if(type==="bfs") {
        path = await bfsAnimated(); // BFS có animation riêng
    }
    else if(type==="dfs") {
        path = dfs();
    }
    else if(type==="astar") {
        path = astar();
    }

    await animatePath(path);
}

// ================= INIT =================
generateMaze();
