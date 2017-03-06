// Room: /d/new_taohua/hai.c
#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "");
        set("long", @LONG
������ӿ�������ȫ��ˮ������������ӿ����
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
        message_vision(HIW"$N�о�Խ��Խ�β�����, ����ֱ���³���\n", ob);
        message_vision("$N��ʱ��ӿ���Ĵ���Ǻ�˼���ˮ����\n"NOR, ob);
        damage = random(5)+50;
        i =  (int)ob->query("kee");
        if (i > 40) ob->improve_skill("dodge", ob->query("con"));
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
        
        if ((int)query("trigger") < 0) {
                message_vision("$N���λذ��ߡ�\n", me);
                me->move(__DIR__"haitan1");
                delete("trigger");
                return;
        }
       if ((int)query("trigger")==100 && random(3)==1){
           message_vision("ͻȻ$N��ǰ������һ�����ɽ,$N����һԾ��ɽ��ɽ. \n",me);
           me->move(__DIR__"bingshan");
	   delete("trigger");
           return;
        }
}

int do_swim(string arg)
{
        int i;
        if (!arg || arg == "") {
                write("�������λ��������Σ�\n");
                return 1;
        }
        if (arg == "north" || arg == "n") {
                add("trigger", 1);
                write("���������ȥ����\n");
                check_trigger();
                return 1;
        }
        if (arg == "south" || arg == "s") {
                i = (int)query("trigger")-1;
                delete("trigger");
                add("trigger", i);
                write("��������ϰ���ȥ����\n");
                check_trigger();
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("trigger");
}
