-- phpMyAdmin SQL Dump
-- version 4.3.0
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Sep 23, 2015 at 05:50 AM
-- Server version: 5.5.43-MariaDB
-- PHP Version: 5.5.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `housetemps`
--

-- --------------------------------------------------------

--
-- Table structure for table `temperature`
--

CREATE TABLE IF NOT EXISTS `temperature` (
`id` int(11) NOT NULL COMMENT 'unique ID',
  `event` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'Event Date and Time',
  `sensor` varchar(30) NOT NULL COMMENT 'Unique ID of the sensor',
  `celsius` varchar(10) NOT NULL COMMENT 'Measured Temperature in Celsius',
  `humidity` varchar(10) NOT NULL COMMENT 'Measured %humidity',
  `datestamp` date NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=1202 DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `temperature`
--
ALTER TABLE `temperature`
 ADD PRIMARY KEY (`id`), ADD KEY `event` (`event`,`sensor`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `temperature`
--
ALTER TABLE `temperature`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'unique ID',AUTO_INCREMENT=1202;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
