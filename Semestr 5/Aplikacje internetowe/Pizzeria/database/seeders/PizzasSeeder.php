<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;

class PizzasSeeder extends Seeder 
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run() 
    {
        DB::table('pizzas')->insert([
            [
                'name' => 'Margherita',
                'priceFor32' => '28',
                'priceFor42' => '32',
            ],
            [
                'name' => 'Hawajska',
                'priceFor32' => '32',
                'priceFor42' => '36',
            ],
            [
                'name' => 'Z szynką i grzybami',
                'priceFor32' => '32',
                'priceFor42' => '36',
            ],
            [
                'name' => 'Z salami',
                'priceFor32' => '30',
                'priceFor42' => '34',
            ],
            [
                'name' => 'Serowa',
                'priceFor32' => '34',
                'priceFor42' => '38',
            ],
            [
                'name' => 'Wegetariańska',
                'priceFor32' => '38',
                'priceFor42' => '42',
            ],
            [
                'name' => 'Mięsna',
                'priceFor32' => '36',
                'priceFor42' => '40',
            ],
            [
                'name' => 'Z kurczakiem',
                'priceFor32' => '32',
                'priceFor42' => '36',
            ]
        ]);
    }
}
