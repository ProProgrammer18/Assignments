// ignore_for_file: prefer_const_constructors

import 'package:assignment_8/helper/constants.dart';
import 'package:flutter/material.dart';
import 'package:fluttertoast/fluttertoast.dart';

import '../widget/my_menu_item.dart';

final GlobalKey<PopupMenuButtonState<int>> _key = GlobalKey();

class PopUpScreen extends StatelessWidget {
  const PopUpScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    Size size = MediaQuery.of(context).size;

    return Scaffold(
      appBar: AppBar(
        backgroundColor: kGreenColor,
        title: const Text(
          "Pop-Up Menu",
          style: TextStyle(fontSize: 22),
        ),
      ),
      body: SizedBox(
        height: size.height,
        width: size.width,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            PopupMenuButton(
              key: _key,
              onSelected: (int idx) async {
                // print(colors[idx]);
                Fluttertoast.showToast(
                  msg: "You clicked: ${colors[idx].toString()}",
                  backgroundColor: color[idx],
                );
              },
              child: Container(
                padding: EdgeInsets.all(10),
                decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(15),
                  border: Border.all(color: kGreenColor, width: 2),
                ),
                child: Text(
                  "Click Me",
                  style: TextStyle(fontSize: 23),
                ),
              ),
              itemBuilder: (context) {
                return const [
                  PopupMenuItem(
                    child: MyMenuItem(
                      name: "Blue",
                      color: kRedColor,
                    ),
                    value: 0,
                  ),
                  PopupMenuItem(
                    child: MyMenuItem(
                      name: "Red",
                      color: kBlueColor,
                    ),
                    value: 1,
                  ),
                  PopupMenuItem(
                    child: MyMenuItem(
                      name: "Orange",
                      color: kPurpleColor,
                    ),
                    value: 2,
                  ),
                ];
              },
            ),
          ],
        ),
      ),
    );
  }
}
