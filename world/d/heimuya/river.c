// Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "猩猩滩");
        set("long", @LONG
水流很急，你耳边全是水声，什么也看不见…
LONG
        );


        setup();
}

void init()
{       object ob;
        add_action("do_swim", "swim");
        if( interactive( ob = this_player()))
        {
        remove_call_out("sinking");
        call_out("sinking", 1, ob);
        }
}

int sinking(object ob)

{
        int i;
        int damage;
        if( environment(ob) == this_object())
        {
        message_vision(HIW"$N感觉越来越游不动了, 身体直往下沉。\n", ob);
        message_vision("$N不时被涌来的大浪呛了几口水！！\n"NOR, ob);
        damage = random(5)+50;
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        if( environment(ob) == this_object())
        call_out("sinking",random(5)+5, ob);
        }
        else

        return 1;
}

void check_trigger()
{
        object me;
        me = this_player();
        if ((int)query("trigger") == 100) {
                message_vision("$N终于游到了岸边, 你爬上岸,累了个半死……\n", me);
                me->move(__DIR__"xxt6");
                delete("trigger");
                return;
        }
        if ((int)query("trigger") < 0) {
                message_vision("$N又游回原来的岸边。\n", me);
                me->move(__DIR__"xxt5");
                delete("trigger");
                return;
        }
}

int do_swim(string arg)
{
        int i;
        if (!arg || arg == "") {
                write("你往东游还是往西游？\n");
                return 1;
        }
        if (arg == "west" || arg == "w") {
                add("trigger", 1);
                write("你奋力向西岸游去……\n");
                check_trigger();
                return 1;
        }
        if (arg == "east" || arg == "e") {
                i = (int)query("trigger")-1;
                delete("trigger");
                add("trigger", i);
                write("你奋力向东岸游去……\n");
                check_trigger();
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("trigger");
}
