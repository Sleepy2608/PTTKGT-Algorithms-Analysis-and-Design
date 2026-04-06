let map;
let markers = [];
let polyline;

const customers = [
    {x:10.8,y:106.7},
    {x:10.81,y:106.71},
    {x:10.79,y:106.69},
    {x:10.82,y:106.72}
];

initMap();

function initMap() {
    map = L.map('map', {
        zoomControl: false   // tắt zoom mặc định bên trái
    }).setView([10.8, 106.7], 13);

    // thêm lại zoom bên phải
    L.control.zoom({
        position: 'topright'
    }).addTo(map);

    L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        attribution: '© OpenStreetMap contributors'
    }).addTo(map);

    customers.forEach((c, i) => {
        let marker = L.marker([c.x, c.y])
            .addTo(map)
            .bindPopup("Điểm " + (i+1));

        markers.push(marker);
    });
}

function solve() {
    fetch("http://localhost:3000/solve", {
        method: "POST",
        headers: {"Content-Type":"application/json"},
        body: JSON.stringify({customers})
    })
    .then(res => res.text())
    .then(data => {
        document.getElementById("output").innerText = data;
        drawRoute(data);
    });
}

function drawRoute(data) {
    if (polyline) {
        map.removeLayer(polyline);
    }

    let lines = data.split("\n");
    let path = [];

    lines.forEach(line => {
        let nums = line.match(/\d+/g);
        if (!nums) return;

        nums.forEach(i => {
            if (customers[i]) {
                path.push([customers[i].x, customers[i].y]);
            }
        });
    });

    polyline = L.polyline(path, {
        color: 'red',
        weight: 4
    }).addTo(map);
}
