inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("������", ({ "sugar" }));
    set_weight(100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "һ�������ǣ���������ϲ�ǲ����ˡ�\n");
          set("unit", "��");
          set("value", 50);
          set("food_remaining", 4);
          set("food_supply", 60);
     }
}

