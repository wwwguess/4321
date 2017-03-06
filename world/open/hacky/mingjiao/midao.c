//midao

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        
        set("short", "����");
        set("long","�������������ң�ǰ����һ�ȴ�ʯ�ţ��������:
                " + HIR "�����صأ��ǽ���Ī��" NOR + "
��˵��߻������أ�Σ���ķ�����ʮ�����������߳����޼���������������\n");

        set("exits", ([    
              "out" : __DIR__"neishi",

        ]));


        setup();

}


void init()
{
        add_action("do_push","push");
        
}

do_push(string arg)
{

        string *midao=({
                                 __DIR__"midao0",
                                 __DIR__"midao1",
                                 __DIR__"midao2",
                                 __DIR__"midao3",
                                 __DIR__"midao4",
                                 __DIR__"midao5",
                                 __DIR__"midao6",
                                 __DIR__"midao7",
                        });

	object me;

        me=this_player();

        if( !arg || arg=="" )
		return notify_fail("push <���>\n");

        if(arg=="men" || arg=="door")
	{
                if(me->query("force")>=300)
        	{
                	message_vision("$N����������ʯ����ȥ,ʯ�Ż����ؿ��ˡ�\n",me);
                	set("exits/enter", midao[random(8)]);

	                remove_call_out("close");
        	        call_out("close", 5, this_object());

	                return 1;
		}

		return notify_fail("�������������\n");

	}
	return notify_fail("��Ҫ��ʲô��\n");
}

void close(object room)
{
        message("vision","ʯ���ƻ�ԭ�ء�\n", room);
        room->delete("exits/enter");
}

int valid_leave(object me,string dir)
{
        me->delete_temp("bagua/xiu");
        me->delete_temp("bagua/sheng");
        me->delete_temp("bagua/shang");
        me->delete_temp("bagua/du");
        me->delete_temp("bagua/gin");
        me->delete_temp("bagua/si");
        me->delete_temp("bagua/jing1");
        me->delete_temp("bagua/kai");

	return ::valid_leave(me,dir);
}