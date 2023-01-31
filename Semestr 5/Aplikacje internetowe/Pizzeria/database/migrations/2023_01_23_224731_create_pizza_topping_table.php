<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('pizza_topping', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedTinyInteger('pizza_id');
            $table->unsignedTinyInteger('topping_id');
            $table->foreign('pizza_id')->references('id')
                    ->on('pizzas')->onUpdate('cascade')->onDelete('cascade');
            $table->foreign('topping_id')->references('id')
                    ->on('toppings')->onUpdate('cascade')->onDelete('cascade');
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('pizza_topping');
    }
};
