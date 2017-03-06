// medicine: zitanhua.c
// Jay 3/18/96
//write by lysh
inherit ITEM;

void setup()
{}


void create()
{
        set_name("∫Ï√µπÂ", ({"hong meigui", "meigui"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "∂‰");
                set("long", "’‚ «“ª∂‰∫Ï√µπÂ°£\n");
                set("value", 20);
        }
        setup();
}


