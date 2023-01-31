<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use DB;

class PizzasToppingsSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        DB::table('pizza_topping')->insert([
            [
                'pizza_id' => '2',
                'topping_id' => '1',
            ],
            [
                'pizza_id' => '2',
                'topping_id' => '2',
            ],
            [
                'pizza_id' => '3',
                'topping_id' => '2',
            ],
            [
                'pizza_id' => '3',
                'topping_id' => '14',
            ],
            [
                'pizza_id' => '4',
                'topping_id' => '17',
            ],
            [
                'pizza_id' => '5',
                'topping_id' => '18',
            ],
            [
                'pizza_id' => '5',
                'topping_id' => '19',
            ],
            [
                'pizza_id' => '5',
                'topping_id' => '20',
            ],
            [
                'pizza_id' => '5',
                'topping_id' => '22',
            ],
            [
                'pizza_id' => '6',
                'topping_id' => '8',
            ],
            [
                'pizza_id' => '6',
                'topping_id' => '14',
            ],
            [
                'pizza_id' => '6',
                'topping_id' => '11',
            ],
            [
                'pizza_id' => '6',
                'topping_id' => '16',
            ],
            [
                'pizza_id' => '6',
                'topping_id' => '12',
            ],
            [
                'pizza_id' => '7',
                'topping_id' => '6',
            ],
            [
                'pizza_id' => '7',
                'topping_id' => '17',
            ],
            [
                'pizza_id' => '7',
                'topping_id' => '5',
            ],
            [
                'pizza_id' => '7',
                'topping_id' => '2',
            ],
            [
                'pizza_id' => '8',
                'topping_id' => '4',
            ],
            [
                'pizza_id' => '8',
                'topping_id' => '9',
            ],
        ]);
    }
}
