
inherit ITEM;

void create()
{
	int weight;

    set_name("竹子", ({ "bamboo" }) );
    set("unit", "根");
    set("long","这是一根玉竹，还有一些竹叶在上面。\n");
    if (random(10) == 9)
    	set_weight(300);
    else
	set_weight(320);
}
