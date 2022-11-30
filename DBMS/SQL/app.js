const mysql = require("mysql");
const dotenv = require("dotenv").config({ path: "./config.env" });
const express = require("express");
const bycrpt = require("bcrypt");
const fs = require("fs");
const app = express();
const alert = require("alert");

app.use(express.static("./public"));
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

let success = fs.readFileSync(`${__dirname}/html/successLogin.html`, "utf-8");

app.get("/", (req, res) => {
  res.status(200).sendFile(`${__dirname}/html/home.html`);
});
app.get("/login", (req, res) => {
  res.status(200).sendFile(`${__dirname}/html/login.html`);
});
app.get("/signup", (req, res) => {
  res.status(200).sendFile(`${__dirname}/html/signup.html`);
});

app.post("/login", async (req, res) => {
  console.log(req.body);
  const studentEmail = req.body.email;
  const studentPassword = req.body.password;
  db.getConnection(async (err, connection) => {
    if (err) throw err;
    const sqlSearch = "SELECT * FROM students WHERE email = ?";
    const search_query = mysql.format(sqlSearch, [studentEmail]);
    await connection.query(search_query, async (err, result) => {
      if (err) throw err;
      if (result.length == 0) {
        alert("User does not exists");
        if (connection) connection.release();
        res.status(404).sendFile(`${__dirname}/html/failLogin.html`);
      } else {
        console.log(studentPassword);
        console.log(result[0].password);
        if (await bycrpt.compare(studentPassword, result[0].password)) {
          userdata = `<container style="margin: 10px;padding:5px;border: 2px solid black; display:inline-block"><h2>Student: ${result[0].name}<br>Email: ${result[0].email} </h2></container>`;
          success = success.replace("#USERDATA", userdata);
          console.log(success);
          console.log("Login successfull!!");
          res.status(200).send(success);
        } else {
          console.log("Password incorrect");
          res.status(400).sendFile(`${__dirname}/html/failLogin.html`);
        }
      }
    });
  });
});

app.post("/signup", async (req, res) => {
  const studentName = req.body.name;
  const studentPhone = req.body.phone;
  const studentAddress = req.body.address;
  const studentEmail = req.body.email;
  const hashedPassword = await bycrpt.hash(req.body.password, 10);

  db.getConnection(async (err, connection) => {
    if (err) throw err;
    const sqlSearch = "SELECT * FROM students WHERE email=?";
    const search_query = mysql.format(sqlSearch, [studentEmail]);
    const sqlInsert = "INSERT INTO students VALUES (0,?,?,?,?,?)";
    const insert_query = mysql.format(sqlInsert, [
      studentName,
      studentEmail,
      studentPhone,
      studentAddress,
      hashedPassword,
    ]);
    await connection.query(search_query, async (err, result) => {
      if (err) throw err;
      console.log("---->Search Results");
      console.log(result.length);

      if (result.length != 0) {
        connection.release();
        alert("User already exists");

        res.sendFile(`${__dirname}/html/home.html`);
      } else {
        await connection.query(insert_query, (err, result) => {
          connection.release();

          if (err) throw err;
          console.log("------->Created new student");
          console.log(result.insertId);
          res.sendFile(`${__dirname}/html/home.html`);
        });
      }
    });
  });
});

// const con = mysql.createConnection({
// host: process.env.HOST,
// user: process.env.USER,
// password: process.env.PASSWORD,
// database: process.env.DATABASE,
// });

const db = mysql.createPool({
  host: process.env.HOST,
  user: process.env.USER,
  password: process.env.PASSWORD,
  database: process.env.DATABASE,
  port: process.env.DB_PORT,
});

// con.connect((err) => {
//   if (err) throw err;
//   console.log("Connected to mysql server");

//=================================================================
//   con.query("CREATE DATABASE nodeDemo", (err, res) => {
//     if (err) throw err;
//     console.log("DATABASE CREATED");
//   });

//=================================================================
// let sql = "CREATE TABLE students (id INT AUTO_INCREMENT PRIMARY KEY,name VARCHAR(255),email VARCHAR(75),phone VARCHAR(15),address VARCHAR(255))";
//   con.query(sql, (err, res) => {
//     if (err) throw err;
//     console.log("Table Created");
//   });
//=================================================================
// });

const port = 80;
app.listen(port, () => {
  console.log("Server running at " + port);
});
