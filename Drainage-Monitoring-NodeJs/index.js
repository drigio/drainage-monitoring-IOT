const express = require("express");
const app = express();
const serialPort = require("serialport");
const Readline = require("@serialport/parser-readline");

const port = new serialPort('COM3', { baudRate: 9600 });
const parser = port.pipe(new Readline({ delimiter: '\n', encoding : 'utf-8' }));

app.set('view engine', 'ejs');

port.on("open", () => {
    console.log('serial port open');
});

var dist = 0;

parser.on('data', data =>{
    console.log('got word from arduino:', data);
    dist = data.split(" ");
    //dist1 = parseInt(dist[0]);
    // if(dist > 10) {
    //     console.log("Good Flow");
    // }
});

app.get('/', (req, res) => {
    res.render('pages/index');
});

app.get('/data', (req, res) => {
    res.json({
        dist : dist
    });
});

app.listen(3000, (err) => {
    if(err) console.log("Error running Express!");
    console.log("Express running on port 3000");
});