import 'package:flutter/material.dart';

class MyMenuItem extends StatelessWidget {
  const MyMenuItem({Key? key, required this.name, required this.color})
      : super(key: key);
  final String name;
  final Color color;

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.all(5),
      width: double.infinity,
      decoration: BoxDecoration(
        color: color,
        border: Border.all(color: Colors.black),
        borderRadius: BorderRadius.circular(5),
      ),
      child: Text(
        name,
        style: const TextStyle(fontSize: 16),
      ),
    );
  }
}
