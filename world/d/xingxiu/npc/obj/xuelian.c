// medicine: xuelian.c
// Jay 3/18/96

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("天山雪莲", ({"xuelian", "lian", "lotus"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支只有在寒冷的地方才能生长的雪莲。\n");
                set("value", 100);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
             this_player()->add("max_force", 1);

// function of this medicine needed here
this_player()->add("max_jingli", 1);
message_vision("$N吃下一棵雪莲，顿时间觉得全身充满了活力 !\n", this_player());

       destruct(this_object());
       return 1;
}

