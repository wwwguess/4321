inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("ˮ��", ({ "boiled dumplings","food" }));
    set_weight(100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "����һ���ֹ�ϸ���ˮ�ȣ��������ܺóԡ�\n");
          set("unit", "��");
          set("value", 50);
          set("food_remaining", 2);
          set("food_supply", 30);
     }
}


