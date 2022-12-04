-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 17 Lis 2021, 18:40
-- Wersja serwera: 10.4.11-MariaDB
-- Wersja PHP: 7.4.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `projekt`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `cart`
--

CREATE TABLE `cart` (
  `id` int(11) NOT NULL,
  `date_time` datetime NOT NULL,
  `total_amount` decimal(8,2) NOT NULL,
  `id_client` int(11) NOT NULL,
  `id_shop` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `cart_product`
--

CREATE TABLE `cart_product` (
  `id_cart` int(11) NOT NULL,
  `id_product` int(11) NOT NULL,
  `quantity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `category`
--

CREATE TABLE `category` (
  `id` int(11) NOT NULL,
  `name` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `client`
--

CREATE TABLE `client` (
  `id` int(11) NOT NULL,
  `login` varchar(45) NOT NULL,
  `hashed_password` char(32) NOT NULL,
  `email` varchar(45) NOT NULL,
  `address` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `info_cart`
--

CREATE TABLE `info_cart` (
  `id` int(11) NOT NULL,
  `id_cart` int(11) NOT NULL,
  `id_message` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `info_media`
--

CREATE TABLE `info_media` (
  `id` int(11) NOT NULL,
  `id_review_product` int(11) DEFAULT NULL,
  `id_review_cart` int(11) DEFAULT NULL,
  `id_media` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `media`
--

CREATE TABLE `media` (
  `id` int(11) NOT NULL,
  `image` blob DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `message`
--

CREATE TABLE `message` (
  `id` int(11) NOT NULL,
  `text` varchar(45) NOT NULL,
  `id_client_from` int(11) NOT NULL,
  `id_client_to` int(11) NOT NULL,
  `send_date` datetime NOT NULL,
  `id_message_status` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `message_status`
--

CREATE TABLE `message_status` (
  `id` int(11) NOT NULL,
  `status` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `order_status`
--

CREATE TABLE `order_status` (
  `id` int(11) NOT NULL,
  `status` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `payment`
--

CREATE TABLE `payment` (
  `id` int(11) NOT NULL,
  `paid_date` datetime NOT NULL,
  `id_payment_method` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `payment_method`
--

CREATE TABLE `payment_method` (
  `id` int(11) NOT NULL,
  `name` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `premium_through`
--

CREATE TABLE `premium_through` (
  `valid_through` datetime NOT NULL,
  `id_client` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `price_history`
--

CREATE TABLE `price_history` (
  `id` int(11) NOT NULL,
  `date` date NOT NULL,
  `price` decimal(8,2) NOT NULL,
  `id_product` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `product`
--

CREATE TABLE `product` (
  `id` int(11) NOT NULL,
  `name` varchar(32) NOT NULL,
  `id_category` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `review_cart`
--

CREATE TABLE `review_cart` (
  `id` int(11) NOT NULL,
  `text` varchar(45) NOT NULL,
  `id_client` int(11) NOT NULL,
  `id_cart` int(11) NOT NULL,
  `date_time` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `review_product`
--

CREATE TABLE `review_product` (
  `id` int(11) NOT NULL,
  `text` varchar(45) NOT NULL,
  `date` datetime NOT NULL,
  `id_product` int(11) NOT NULL,
  `id_client` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `shop`
--

CREATE TABLE `shop` (
  `id` int(11) NOT NULL,
  `name` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `_order`
--

CREATE TABLE `_order` (
  `id` int(11) NOT NULL,
  `date_time` datetime NOT NULL,
  `id_payment` int(11) NOT NULL,
  `id_order_status` int(11) NOT NULL,
  `id_cart` int(11) NOT NULL,
  `id_client` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `cart`
--
ALTER TABLE `cart`
  ADD PRIMARY KEY (`id`),
  ADD KEY `cart_shop_FK` (`id_shop`),
  ADD KEY `cart_client_FK` (`id_client`) USING BTREE;

--
-- Indeksy dla tabeli `cart_product`
--
ALTER TABLE `cart_product`
  ADD PRIMARY KEY (`id_cart`,`id_product`),
  ADD KEY `cart_product_product_FK` (`id_product`);

--
-- Indeksy dla tabeli `category`
--
ALTER TABLE `category`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `name` (`name`);

--
-- Indeksy dla tabeli `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `login` (`login`),
  ADD UNIQUE KEY `email` (`email`);

--
-- Indeksy dla tabeli `info_cart`
--
ALTER TABLE `info_cart`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_cart` (`id_cart`),
  ADD KEY `id_message` (`id_message`);

--
-- Indeksy dla tabeli `info_media`
--
ALTER TABLE `info_media`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_review_product` (`id_review_product`),
  ADD KEY `id_review_cart` (`id_review_cart`),
  ADD KEY `id_media` (`id_media`);

--
-- Indeksy dla tabeli `media`
--
ALTER TABLE `media`
  ADD PRIMARY KEY (`id`);

--
-- Indeksy dla tabeli `message`
--
ALTER TABLE `message`
  ADD PRIMARY KEY (`id`),
  ADD KEY `message_status_FK` (`id_message_status`),
  ADD KEY `id_client_from` (`id_client_from`),
  ADD KEY `id_client_to` (`id_client_to`);

--
-- Indeksy dla tabeli `message_status`
--
ALTER TABLE `message_status`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `status` (`status`);

--
-- Indeksy dla tabeli `order_status`
--
ALTER TABLE `order_status`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `status` (`status`);

--
-- Indeksy dla tabeli `payment`
--
ALTER TABLE `payment`
  ADD PRIMARY KEY (`id`),
  ADD KEY `payment_method_FK` (`id_payment_method`);

--
-- Indeksy dla tabeli `payment_method`
--
ALTER TABLE `payment_method`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `name` (`name`);

--
-- Indeksy dla tabeli `premium_through`
--
ALTER TABLE `premium_through`
  ADD KEY `id_client` (`id_client`);

--
-- Indeksy dla tabeli `price_history`
--
ALTER TABLE `price_history`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_product` (`id_product`);

--
-- Indeksy dla tabeli `product`
--
ALTER TABLE `product`
  ADD PRIMARY KEY (`id`),
  ADD KEY `product_category_FK` (`id_category`);

--
-- Indeksy dla tabeli `review_cart`
--
ALTER TABLE `review_cart`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_cart` (`id_cart`),
  ADD KEY `id_client` (`id_client`);

--
-- Indeksy dla tabeli `review_product`
--
ALTER TABLE `review_product`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_product` (`id_product`),
  ADD KEY `id_client` (`id_client`);

--
-- Indeksy dla tabeli `shop`
--
ALTER TABLE `shop`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `name` (`name`);

--
-- Indeksy dla tabeli `_order`
--
ALTER TABLE `_order`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_cart` (`id_cart`),
  ADD KEY `id_client` (`id_client`),
  ADD KEY `id_payment` (`id_payment`),
  ADD KEY `id_order_status` (`id_order_status`);

--
-- Ograniczenia dla zrzutów tabel
--

--
-- Ograniczenia dla tabeli `cart`
--
ALTER TABLE `cart`
  ADD CONSTRAINT `cart_ibfk_1` FOREIGN KEY (`id_client`) REFERENCES `client` (`id`),
  ADD CONSTRAINT `cart_shop_FK` FOREIGN KEY (`id_shop`) REFERENCES `shop` (`id`);

--
-- Ograniczenia dla tabeli `cart_product`
--
ALTER TABLE `cart_product`
  ADD CONSTRAINT `cart_product_cart_FK` FOREIGN KEY (`id_cart`) REFERENCES `cart` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `cart_product_ibfk_1` FOREIGN KEY (`id_cart`) REFERENCES `cart` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `cart_product_ibfk_2` FOREIGN KEY (`id_product`) REFERENCES `product` (`id`),
  ADD CONSTRAINT `cart_product_ibfk_3` FOREIGN KEY (`id_cart`) REFERENCES `cart` (`id`),
  ADD CONSTRAINT `cart_product_product_FK` FOREIGN KEY (`id_product`) REFERENCES `product` (`id`),
  ADD CONSTRAINT `id_cart` FOREIGN KEY (`id_cart`) REFERENCES `cart` (`id`);

--
-- Ograniczenia dla tabeli `info_cart`
--
ALTER TABLE `info_cart`
  ADD CONSTRAINT `info_cart_ibfk_1` FOREIGN KEY (`id_cart`) REFERENCES `cart` (`id`),
  ADD CONSTRAINT `info_cart_ibfk_2` FOREIGN KEY (`id_message`) REFERENCES `message` (`id`);

--
-- Ograniczenia dla tabeli `info_media`
--
ALTER TABLE `info_media`
  ADD CONSTRAINT `info_media_ibfk_1` FOREIGN KEY (`id_review_product`) REFERENCES `review_product` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `info_media_ibfk_2` FOREIGN KEY (`id_review_cart`) REFERENCES `review_cart` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `info_media_ibfk_3` FOREIGN KEY (`id_media`) REFERENCES `media` (`id`) ON DELETE CASCADE;

--
-- Ograniczenia dla tabeli `message`
--
ALTER TABLE `message`
  ADD CONSTRAINT `message_ibfk_1` FOREIGN KEY (`id_client_from`) REFERENCES `client` (`id`),
  ADD CONSTRAINT `message_ibfk_2` FOREIGN KEY (`id_client_to`) REFERENCES `client` (`id`),
  ADD CONSTRAINT `message_ibfk_3` FOREIGN KEY (`id_client_from`) REFERENCES `client` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `message_ibfk_4` FOREIGN KEY (`id_client_to`) REFERENCES `client` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `message_status_FK` FOREIGN KEY (`id_message_status`) REFERENCES `message_status` (`id`);

--
-- Ograniczenia dla tabeli `payment`
--
ALTER TABLE `payment`
  ADD CONSTRAINT `payment_method_FK` FOREIGN KEY (`id_payment_method`) REFERENCES `payment_method` (`id`);

--
-- Ograniczenia dla tabeli `premium_through`
--
ALTER TABLE `premium_through`
  ADD CONSTRAINT `premium_through_ibfk_1` FOREIGN KEY (`id_client`) REFERENCES `client` (`id`);

--
-- Ograniczenia dla tabeli `price_history`
--
ALTER TABLE `price_history`
  ADD CONSTRAINT `price_history_ibfk_1` FOREIGN KEY (`id_product`) REFERENCES `product` (`id`) ON DELETE CASCADE;

--
-- Ograniczenia dla tabeli `product`
--
ALTER TABLE `product`
  ADD CONSTRAINT `product_category_FK` FOREIGN KEY (`id_category`) REFERENCES `category` (`id`);

--
-- Ograniczenia dla tabeli `review_cart`
--
ALTER TABLE `review_cart`
  ADD CONSTRAINT `review_cart_ibfk_1` FOREIGN KEY (`id_cart`) REFERENCES `cart` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `review_cart_ibfk_2` FOREIGN KEY (`id_client`) REFERENCES `client` (`id`);

--
-- Ograniczenia dla tabeli `review_product`
--
ALTER TABLE `review_product`
  ADD CONSTRAINT `review_product_ibfk_1` FOREIGN KEY (`id_product`) REFERENCES `product` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `review_product_ibfk_2` FOREIGN KEY (`id_client`) REFERENCES `client` (`id`);

--
-- Ograniczenia dla tabeli `_order`
--
ALTER TABLE `_order`
  ADD CONSTRAINT `_order_ibfk_1` FOREIGN KEY (`id_cart`) REFERENCES `cart` (`id`),
  ADD CONSTRAINT `_order_ibfk_2` FOREIGN KEY (`id_client`) REFERENCES `client` (`id`),
  ADD CONSTRAINT `_order_ibfk_3` FOREIGN KEY (`id_payment`) REFERENCES `payment` (`id`),
  ADD CONSTRAINT `_order_ibfk_4` FOREIGN KEY (`id_order_status`) REFERENCES `order_status` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
