<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use DB;

class ToppingsSeeder extends Seeder 
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run() 
    {
        DB::table('toppings')->insert(
        [
            [
                'name' => 'ananas',
            ],
            [
                'name' => 'szynka',
            ],
            [
                'name' => 'boczek',
            ],
            [
                'name' => 'cebula',
            ],
            [
                'name' => 'bekon',
            ],
            [
                'name' => 'kiełbasa',
            ],
            [
                'name' => 'krewetki',
            ],
            [
                'name' => 'kukurydza',
            ],
            [
                'name' => 'kurczak',
            ],
            [
                'name' => 'oliwki',
            ],
            [
                'name' => 'papryka',
            ],
            [
                'name' => 'brokuły',
            ],
            [
                'name' => 'chilli',
            ],
            [
                'name' => 'pieczarki',
            ],
            [
                'name' => 'fasola',
            ],
            [
                'name' => 'pomidor',
            ],
            [
                'name' => 'salami',
            ],
            [
                'name' => 'ser ementaler',
            ],
            [
                'name' => 'ser parmezan',
            ],
            [
                'name' => 'ser kozi',
            ],
            [
                'name' => 'szpinak',
            ],
            [
                'name' => 'ser mozzarella',
            ]
        ]);
    }
}
