inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("��Ƥ��Ѽ", ({ "duck","food" }));
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "����һֻ���˶�������ˮ�ġ�������Ŀ�Ѽ��\n");
          set("unit", "ֻ");
          set("value", 50);
          set("food_remaining", 5);
          set("food_supply", 80);
     }
}


