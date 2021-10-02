import { useEffect, useState } from "react";
import axios from "axios";
import "./App.css";
import Coin from "./components/Coin";
function App() {
  const [coins, setCoins] = useState([]);
  const [search, setSearchterm] = useState("");
  useEffect(() => {
    axios
      .get(
        "https://api.coingecko.com/api/v3/coins/markets?vs_currency=usd&order=market_cap_desc&per_page=100&page=1&sparkline=false"
      )
      .then((response) => {
        setCoins(response.data);
        console.log(response.data);
      })
      .catch((error) => console.error(error));
  }, []);
  const handleChange = (e) => {
    setSearchterm(e.target.value);
  };

  const filteredCoins = coins.filter((coin) =>
    coin.name.toLowerCase().includes(search.toLowerCase())
  );
  return (
    <div className="App">
      <center>
        <h1 className="main-heading">
          <span className="underline">Cryptocurrency Price Tracker</span>
        </h1>
      </center>
      <center>
        <form>
          <input
            className="input"
            type="text"
            placeholder="Search a Coin"
            onChange={handleChange}
          />
        </form>
      </center>
      <div className="container">
        {filteredCoins.map((coin) => {
          return (
            <Coin
              key={coin.id}
              name={coin.name}
              price={coin.current_price}
              symbol={coin.symbol}
              marketcap={coin.market_cap}
              volume={coin.total_volume}
              image={coin.image}
              priceChange={coin.price_change_percentage_24h}
            />
          );
        })}
      </div>
    </div>
  );
}

export default App;
