import React from "react";
import "./Coins.css";
const Coin = ({
  name,
  price,
  symbol,
  marketcap,
  volume,
  image,
  priceChange,
}) => {
  return (
    <div className="coin">
      <center>
        <img src={image} className="coin-logo" alt="coin" />
      </center>
      <div className="coin-content">
        <center>
          <h1 className="coin-title">{name}</h1>
        </center>
        <center>
          <p className="coin-symbol">{symbol}</p>
        </center>
      </div>
      <center>
        {" "}
        <p className="coin-price">{price.toLocaleString()}</p>
        <p className="coin-marketcap">
          Market Cap: ${marketcap.toLocaleString()}
        </p>
        <p className="coin-volume">
          Volume (24Hrs): ${volume.toLocaleString()}
        </p>
      </center>
      {priceChange < 0 ? (
        <div className="priceContainerDown">
          <i className="fas fa-arrow-down"></i>
          <p className="priceChange">{priceChange.toFixed(2)}%</p>
        </div>
      ) : (
        <div className="priceContainerUp">
          <i className="fas fa-arrow-up"></i>
          <p className="priceChange">{priceChange.toFixed(2)}%</p>
        </div>
      )}
    </div>
  );
};
export default Coin;
