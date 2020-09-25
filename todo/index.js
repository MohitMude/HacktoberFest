const express = require("express");
const bodyParser = require("body-parser");

const app = express();
let items = ["lala", "when i ", "poped off"];

app.use(express.static("public"));
app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));

app.get('/', function(req, res) {
    let today = new Date();

    let options = {
        day: "numeric",
        month: "long",
        weekday: "long"
    };
    let day = today.toLocaleDateString("en-US", options);

    res.render("list", { weekOfDay: day, newlistItems: items });

});

app.post('/', function(req, res) {
    let item = req.body.newItem;
    items.push(item);
    res.redirect('/');
})

app.listen(process.env.PORT || 3000, function() {
    console.log("yeah server running");
});