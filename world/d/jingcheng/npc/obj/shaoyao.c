// medicine: zitanhua.c
// Jay 3/18/96
//write by lysh
inherit ITEM;

void setup()
{}


void create()
{
        set_name("…÷“©", ({"shao yao", "shao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "∂‰");
                set("long", "’‚ «“ª∂‰…÷“©°£\n");
                set("value", 15);
        }
        setup();
}


