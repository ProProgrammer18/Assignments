class Contact {
  String contactName = "";
  String contactNo = "";

  Contact(name, no) {
    contactName = name;
    contactNo = no;
  }
}

class ContactList {
  final List<Contact> contactList = [
    Contact('Om', "1234567890"),
    Contact('Ritesh', "1234567890"),
    Contact('Daulatrao', "1234567890"),
    Contact('Suyash', "1234567890"),
    Contact('Atharv', "1234567890"),
    Contact('Swapnil', "1234567890"),
  ];
}
