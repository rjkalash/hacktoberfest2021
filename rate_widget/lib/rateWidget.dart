import 'package:flutter/material.dart';

class RateWidget extends StatefulWidget {
  const RateWidget({ 
    this.maximumRating,
   required this.onRatingSelected,
   }) ;
  final maximumRating ; 
  final Function(int) onRatingSelected;
  @override
  _RateWidgetState createState() => _RateWidgetState();
}

class _RateWidgetState extends State<RateWidget> {
  int _currentRating = 0;
  Widget _buildRatingStar(int index){
    if(index < _currentRating){
      return Icon(Icons.star , color: Colors.orange,);
    }else{
      return Icon(Icons.star_border_outlined);
    }
    
  }

  Widget _buildBody(){
  final stars = List<Widget>.generate(widget.maximumRating, (index) {
    return _currentRating ==0 ? GestureDetector(
      child: Container(child: _buildRatingStar(index)),
      onTap: (){
        setState(() {
                  _currentRating = index +1;
                });
      },
    ):Container(child: _buildRatingStar(index));
  }  );

  return Row(
    mainAxisAlignment: MainAxisAlignment.center,
    children: stars,
  );
  }
  @override
  Widget build(BuildContext context) {
    return _buildBody();
  }
}