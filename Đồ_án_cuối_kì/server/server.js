const express = require("express");
const cors = require("cors");
const { exec } = require("child_process");
const fs = require("fs");
const path = require("path");

const app = express();
app.use(cors());
app.use(express.json());

app.get("/", (req, res) => {
    res.send("Server OK");
});

app.post("/solve", (req, res) => {
    const customers = req.body.customers;

    let input = customers.length + "\n";
    customers.forEach(c => {
        input += `${c.x} ${c.y}\n`;
    });

    const inputPath = path.join(__dirname, "../data/input.txt");
    fs.writeFileSync(inputPath, input);

    const exePath = path.join(__dirname, "../backend-cpp/vrp.exe");

    exec(`${exePath} < "${inputPath}"`, (err, stdout, stderr) => {
        if (err) {
            console.error(stderr);
            return res.status(500).send("Lỗi chạy C++");
        }
        res.send(stdout);
    });
});

app.listen(3000, () => {
    console.log("Server chạy tại http://localhost:3000");
});
