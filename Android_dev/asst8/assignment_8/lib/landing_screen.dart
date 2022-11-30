// ignore_for_file: prefer_const_constructors

import 'package:assignment_8/helper/constants.dart';
import 'package:assignment_8/screens/context_screen.dart';
import 'package:assignment_8/screens/popup_screen.dart';
import 'package:flutter/material.dart';

class LandingScreen extends StatelessWidget {
  const LandingScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    Size size = MediaQuery.of(context).size;

    return Scaffold(
      body: SizedBox(
        height: size.height,
        width: size.width,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            MyButton(
              name: "PopUp Menu",
              color: kGreenColor,
              onTap: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => PopUpScreen(),
                  ),
                );
              },
            ),
            SizedBox(height: 30),
            MyButton(
              name: "Context Menu",
              color: kPinkColor,
              onTap: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => ContextScreen(),
                  ),
                );
              },
            ),
          ],
        ),
      ),
    );
  }
}

class MyButton extends StatelessWidget {
  const MyButton({
    Key? key,
    required this.name,
    required this.color,
    required this.onTap,
  }) : super(key: key);
  final String name;
  final Color color;
  final Function onTap;

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {
        onTap();
      },
      child: Container(
        height: 60,
        width: MediaQuery.of(context).size.width * 0.5,
        alignment: Alignment.center,
        decoration: BoxDecoration(
            color: color, borderRadius: BorderRadius.circular(15)),
        child: Text(
          name,
          style: TextStyle(
            fontSize: 22,
            fontWeight: FontWeight.bold,
            color: Colors.white,
          ),
        ),
      ),
    );
  }
}
