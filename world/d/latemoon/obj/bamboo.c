
inherit ITEM;

void create()
{
	int weight;

    set_name("����", ({ "bamboo" }) );
    set("unit", "��");
    set("long","����һ�����񣬻���һЩ��Ҷ�����档\n");
    if (random(10) == 9)
    	set_weight(300);
    else
	set_weight(320);
}
