// ignore_for_file: prefer_const_constructors, prefer_const_literals_to_create_immutables

import 'package:assignment_8/helper/constants.dart';
import 'package:assignment_8/helper/contacts.dart';
import 'package:flutter/material.dart';
import 'package:fluttertoast/fluttertoast.dart';

import '../widget/my_menu_item.dart';

class ContextScreen extends StatelessWidget {
  const ContextScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: kPinkColor,
        title: const Text(
          "Context Menu",
          style: TextStyle(fontSize: 22),
        ),
      ),
      body: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 16.0, vertical: 32),
        child: ListView.builder(
          physics: BouncingScrollPhysics(),
          itemCount: ContactList().contactList.length,
          itemBuilder: (context, idx) {
            return Column(
              children: [
                PopupMenuButton(
                  onSelected: (int index) {
                    if (index == 0) {
                      Fluttertoast.showToast(
                          msg:
                              "Call ${ContactList().contactList[idx].contactName}");
                    } else {
                      Fluttertoast.showToast(
                          msg:
                              "Message ${ContactList().contactList[idx].contactName}");
                    }
                  },
                  child: Container(
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(15),
                      border: Border.all(color: kPinkColor, width: 2),
                    ),
                    child: MyListTile(idx: idx),
                  ),
                  itemBuilder: (context) {
                    return const [
                      PopupMenuItem(
                        child: MyMenuItem(
                          name: "Call",
                          color: Colors.white,
                        ),
                        value: 0,
                      ),
                      PopupMenuItem(
                        child: MyMenuItem(
                          name: "Message",
                          color: Colors.white,
                        ),
                        value: 1,
                      ),
                    ];
                  },
                ),
                Divider(),
              ],
            );
          },
        ),
      ),
    );
  }
}

class MyListTile extends StatelessWidget {
  const MyListTile({
    Key? key,
    required this.idx,
  }) : super(key: key);
  final int idx;

  @override
  Widget build(BuildContext context) {
    return ListTile(
      leading: Icon(Icons.call),
      title: Text(
        ContactList().contactList[idx].contactName,
        style: TextStyle(),
      ),
      subtitle: Text(
        ContactList().contactList[idx].contactNo,
        style: TextStyle(),
      ),
    );
  }
}
