const express = require("express");
const fs = require("fs");
const dotenv = require("dotenv").config({ path: "./config.env" });
const mongoose = require("mongoose");
const app = express();

app.use(express.json());

app.use(express.static("./public"));

app.use(express.urlencoded({ extended: true }));

mongoose.connect(process.env.DATABASE).then(() => {
  console.log("Connected to database");
});

// ! GET REQUESTS

app.get("/", (req, res) => {
  res.status(200).sendFile(`${__dirname}/public/html/home.html`);
});

app.get("/login", (req, res) => {
  res.status(200).sendFile(`${__dirname}/public/html/login.html`);
});

app.get("/signup", (req, res) => {
  res.status(200).sendFile(`${__dirname}/public/html/signup.html`);
});

// ! POST REQUESTS

const studentSchema = new mongoose.Schema({
  name: {
    type: String,
    required: [true, "Name required"],
  },
  email: {
    type: String,
    unique: true,
    required: [true, "Email required"],
  },
  password: {
    type: String,
    required: [true, "Password required"],
  },
  phone: {
    type: Number,
    required: [true, "Phone number required"],
  },
  address: {
    type: String,
    required: [true, "Address required"],
  },
});

const Student = mongoose.model("Student", studentSchema);

app.post("/login", async (req, res) => {
  const studentEmail = req.body.email;
  const studentPassword = req.body.password;
  const query = await Student.find(req.body);
  let success;
  await fs.readFile(
    `${__dirname}/public/html/successLogin.html`,
    "utf8",
    (err, data) => {
      if (err) {
        console.error(err);
        return;
      }
      success = data;
      console.log(query);
      if (query.length) {
        userdata = `<container style="margin: 10px;padding:5px;border: 2px solid black; display:inline-block"><h2>Student: ${query[0].name}<br>Email: ${query[0].email} </h2></container>`;
        success = success.replace("#USERDATA", userdata);
        console.log("Login successfull!!");
        res.status(200).send(success);
      } else {
        res.status(404).sendFile(`${__dirname}/public/html/failLogin.html`);
      }
    }
  );
});

app.post("/signup", async (req, res) => {
  const studentName = req.body.name;
  const studentPhone = req.body.phone;
  const studentAddress = req.body.address;
  const studentEmail = req.body.email;
  const studentPassword = req.body.password;

  const query = await Student.create({
    name: studentName,
    email: studentEmail,
    password: studentPassword,
    phone: studentPhone,
    address: studentAddress,
  })
    .then(() => {
      // let success;
      // userdata = `<container style="margin: 10px;padding:5px;border: 2px solid black; display:inline-block"><h2>Student: ${query.name}<br>Email: ${query.email} </h2></container>`;
      // success = success.replace("#USERDATA", userdata);
      // console.log("Login successfull!!");
      // res.status(200).send(success);
      res.status(200).sendFile(`${__dirname}/public/html/login.html`);
    })
    .catch((err) => {
      res.status(404).sendFile(`${__dirname}/public/html/failLogin.html`);
      console.log(err);
    });
});

app.listen(80, () => {
  console.log("Server running at port 80");
});
