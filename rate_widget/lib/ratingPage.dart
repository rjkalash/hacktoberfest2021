import 'package:flutter/material.dart';
import 'package:rate_widget/rateWidget.dart';

class RatingPage extends StatefulWidget {
  const RatingPage({ Key? key }) : super(key: key);

  @override
  _RatingPageState createState() => _RatingPageState();
}

class _RatingPageState extends State<RatingPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Rating Widget'),),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            RateWidget(onRatingSelected: (index){} , maximumRating: 5, )
          ],
        ),
      ),
    );
  }
}