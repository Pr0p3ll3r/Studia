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
        Schema::create('order_items', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->bigInteger('order_id')->unsigned();
            $table->tinyInteger('pizza_id')->unsigned();
            $table->tinyInteger('quantity')->unsigned();
            $table->string('size');
            $table->unsignedDouble('price', 5, 2);
            $table->foreign('order_id')->references('id')
                    ->on('orders')->onUpdate('cascade')->onDelete('cascade');
            $table->foreign('pizza_id')->references('id')
                    ->on('pizzas')->onUpdate('cascade');
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('order_pizzas');
    }
};
