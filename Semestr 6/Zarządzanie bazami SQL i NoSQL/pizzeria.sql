-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema pizzeria
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema pizzeria
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `pizzeria` DEFAULT CHARACTER SET utf8mb4 ;
USE `pizzeria` ;

-- -----------------------------------------------------
-- Table `pizzeria`.`role`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`role` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `pizzeria`.`user`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`user` (
  `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `username` VARCHAR(16) NOT NULL,
  `password` VARCHAR(45) NOT NULL,
  `email` VARCHAR(45) NOT NULL,
  `role_id` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `email_UNIQUE` (`email` ASC),
  UNIQUE INDEX `username_UNIQUE` (`username` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_user_role1_idx` (`role_id` ASC),
  CONSTRAINT `fk_user_role1`
    FOREIGN KEY (`role_id`)
    REFERENCES `pizzeria`.`role` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `pizzeria`.`delivery_person`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`delivery_person` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `first_name` VARCHAR(16) NOT NULL,
  `last_name` VARCHAR(45) NOT NULL,
  `user_id` BIGINT UNSIGNED NOT NULL,
  PRIMARY KEY (`id`, `user_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_delivery_person_user1_idx` (`user_id` ASC),
  UNIQUE INDEX `user_id_UNIQUE` (`user_id` ASC),
  CONSTRAINT `fk_delivery_person_user1`
    FOREIGN KEY (`user_id`)
    REFERENCES `pizzeria`.`user` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `pizzeria`.`customer`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`customer` (
  `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `first_name` VARCHAR(16) NOT NULL,
  `last_name` VARCHAR(45) NULL,
  `phone_number` VARCHAR(9) NOT NULL,
  `user_id` BIGINT UNSIGNED NOT NULL,
  PRIMARY KEY (`id`, `user_id`),
  INDEX `fk_customer_user1_idx` (`user_id` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  CONSTRAINT `fk_customer_user1`
    FOREIGN KEY (`user_id`)
    REFERENCES `pizzeria`.`user` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 3
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `pizzeria`.`payment_method`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`payment_method` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `pizzeria`.`order_status`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`order_status` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `pizzeria`.`order`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`order` (
  `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `customer_id` BIGINT UNSIGNED NOT NULL,
  `total_amount` DECIMAL(6,2) UNSIGNED NOT NULL,
  `order_date` DATETIME NOT NULL,
  `comment` VARCHAR(255) NULL DEFAULT NULL,
  `payment_method_id` INT UNSIGNED NOT NULL,
  `order_status_id` INT UNSIGNED NOT NULL,
  `is_delivery` TINYINT NOT NULL,
  PRIMARY KEY (`id`, `customer_id`),
  INDEX `fk_orders_customers1_idx` (`customer_id` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_orders_payment_method1_idx` (`payment_method_id` ASC),
  INDEX `fk_order_order_status1_idx` (`order_status_id` ASC),
  CONSTRAINT `fk_order_customer`
    FOREIGN KEY (`customer_id`)
    REFERENCES `pizzeria`.`customer` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_order_payment_method`
    FOREIGN KEY (`payment_method_id`)
    REFERENCES `pizzeria`.`payment_method` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_order_order_status1`
    FOREIGN KEY (`order_status_id`)
    REFERENCES `pizzeria`.`order_status` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 25
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `pizzeria`.`delivery`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`delivery` (
  `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `street` VARCHAR(45) NOT NULL,
  `houseNumber` VARCHAR(5) NOT NULL,
  `apartmentNumber` VARCHAR(5) NULL DEFAULT NULL,
  `postal_code` VARCHAR(6) NOT NULL,
  `order_id` BIGINT UNSIGNED NOT NULL,
  `delivery_person_id` INT UNSIGNED NULL,
  PRIMARY KEY (`id`, `order_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_delivery_address_delivery_person1_idx` (`delivery_person_id` ASC),
  INDEX `fk_delivery_address_order1_idx` (`order_id` ASC),
  CONSTRAINT `fk_delivery_address_delivery_person1`
    FOREIGN KEY (`delivery_person_id`)
    REFERENCES `pizzeria`.`delivery_person` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_delivery_address_order1`
    FOREIGN KEY (`order_id`)
    REFERENCES `pizzeria`.`order` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 25
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `pizzeria`.`order_review`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`order_review` (
  `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `rating` TINYINT UNSIGNED NOT NULL,
  `comment` VARCHAR(500) NULL,
  `order_id` BIGINT UNSIGNED NOT NULL,
  PRIMARY KEY (`id`, `order_id`),
  INDEX `order_review_order_id_foreign` (`order_id` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  UNIQUE INDEX `order_id_UNIQUE` (`order_id` ASC),
  CONSTRAINT `order_review_order_id_foreign`
    FOREIGN KEY (`order_id`)
    REFERENCES `pizzeria`.`order` (`id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
AUTO_INCREMENT = 7
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `pizzeria`.`custom_pizza`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`custom_pizza` (
  `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `size` VARCHAR(45) NOT NULL,
  `price` DECIMAL(6,2) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `pizzeria`.`type`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`type` (
  `id` TINYINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC),
  UNIQUE INDEX `idtype_UNIQUE` (`id` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `pizzeria`.`product`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`product` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  `type_id` TINYINT UNSIGNED NOT NULL,
  `image` BLOB NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_product_type1_idx` (`type_id` ASC),
  CONSTRAINT `fk_product_type1`
    FOREIGN KEY (`type_id`)
    REFERENCES `pizzeria`.`type` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `pizzeria`.`order_position`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`order_position` (
  `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `quantity` TINYINT UNSIGNED NOT NULL,
  `price` DECIMAL(6,2) UNSIGNED NOT NULL,
  `order_id` BIGINT UNSIGNED NOT NULL,
  `custom_pizza_id` BIGINT UNSIGNED NULL,
  `product_id` INT UNSIGNED NULL,
  PRIMARY KEY (`id`, `order_id`),
  INDEX `order_item_order_id_foreign` (`order_id` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_order_position_custom_pizza1_idx` (`custom_pizza_id` ASC),
  INDEX `fk_order_position_product1_idx` (`product_id` ASC),
  UNIQUE INDEX `custom_pizza_id_UNIQUE` (`custom_pizza_id` ASC),
  CONSTRAINT `order_item_order_id_foreign`
    FOREIGN KEY (`order_id`)
    REFERENCES `pizzeria`.`order` (`id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_order_position_custom_pizza1`
    FOREIGN KEY (`custom_pizza_id`)
    REFERENCES `pizzeria`.`custom_pizza` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_order_position_product1`
    FOREIGN KEY (`product_id`)
    REFERENCES `pizzeria`.`product` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 24
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `pizzeria`.`pizza`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`pizza` (
  `id` TINYINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `product_id` INT UNSIGNED NOT NULL,
  `price_small` DECIMAL(5,2) UNSIGNED NOT NULL,
  `price_medium` DECIMAL(5,2) UNSIGNED NOT NULL,
  `price_big` DECIMAL(5,2) UNSIGNED NOT NULL,
  PRIMARY KEY (`id`, `product_id`),
  INDEX `fk_pizza_product1_idx` (`product_id` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  UNIQUE INDEX `product_id_UNIQUE` (`product_id` ASC),
  CONSTRAINT `fk_pizza_product1`
    FOREIGN KEY (`product_id`)
    REFERENCES `pizzeria`.`product` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 9
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `pizzeria`.`topping`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`topping` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  `price` DECIMAL(4,2) UNSIGNED NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC))
ENGINE = InnoDB
AUTO_INCREMENT = 23
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `pizzeria`.`pizza_topping`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`pizza_topping` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `pizza_id` TINYINT UNSIGNED NOT NULL,
  `topping_id` INT UNSIGNED NOT NULL,
  INDEX `pizza_topping_pizza_id_foreign` (`pizza_id` ASC),
  INDEX `pizza_topping_topping_id_foreign` (`topping_id` ASC),
  PRIMARY KEY (`id`, `pizza_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  CONSTRAINT `pizza_topping_pizza_id_foreign`
    FOREIGN KEY (`pizza_id`)
    REFERENCES `pizzeria`.`pizza` (`id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `pizza_topping_topping_id_foreign`
    FOREIGN KEY (`topping_id`)
    REFERENCES `pizzeria`.`topping` (`id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
AUTO_INCREMENT = 21
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `pizzeria`.`customer_address`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`customer_address` (
  `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `street` VARCHAR(45) NOT NULL,
  `houseNumber` VARCHAR(5) NOT NULL,
  `apartmentNumber` VARCHAR(5) NULL DEFAULT NULL,
  `postal_code` VARCHAR(6) NOT NULL,
  `customer_id` BIGINT UNSIGNED NOT NULL,
  PRIMARY KEY (`id`, `customer_id`),
  INDEX `fk_customer_address_customer1_idx` (`customer_id` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  CONSTRAINT `fk_customer_address_customer`
    FOREIGN KEY (`customer_id`)
    REFERENCES `pizzeria`.`customer` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 25
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `pizzeria`.`custom_pizza_topping`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`custom_pizza_topping` (
  `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `topping_id` INT UNSIGNED NOT NULL,
  `custom_pizza_id` BIGINT UNSIGNED NOT NULL,
  PRIMARY KEY (`id`, `custom_pizza_id`),
  INDEX `fk_custom_pizza_topping_topping1_idx` (`topping_id` ASC),
  INDEX `fk_custom_pizza_topping_custom_pizza1_idx` (`custom_pizza_id` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  CONSTRAINT `fk_custom_pizza_topping_topping1`
    FOREIGN KEY (`topping_id`)
    REFERENCES `pizzeria`.`topping` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_custom_pizza_topping_custom_pizza1`
    FOREIGN KEY (`custom_pizza_id`)
    REFERENCES `pizzeria`.`custom_pizza` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `pizzeria`.`non_pizza`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `pizzeria`.`non_pizza` (
  `id` TINYINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `product_id` INT UNSIGNED NOT NULL,
  `price` DECIMAL(5,2) UNSIGNED NOT NULL,
  PRIMARY KEY (`id`, `product_id`),
  INDEX `fk_non_pizza_product1_idx` (`product_id` ASC),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  UNIQUE INDEX `product_id_UNIQUE` (`product_id` ASC),
  CONSTRAINT `fk_non_pizza_product1`
    FOREIGN KEY (`product_id`)
    REFERENCES `pizzeria`.`product` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
