inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("��������", ({ "chicken","food" }));
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "����һ�������ɿڵļ��ȡ�\n");
          set("unit", "ֻ");
          set("value", 50);
          set("food_remaining", 5);
          set("food_supply", 70);
     }
}


