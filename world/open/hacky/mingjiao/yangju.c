//yangdingtian room

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
    ����һ�伫���ʯ�ң����ϴ������飬��Ȼ����Ȼ��ʯ�������µ����������ã�
���������·���δ�þ������ó���һ��һŮ��
LONG
        );

        set("exit", ([
        ]));
        set("item_desc", ([
		"����" : "�����õ����Ժ����з��š�\n" ,
	    "skeleton" : "�����õ����Ժ����з��š�\n"
	]));
        setup();
}

void init()
{
        add_action("do_pick","pick");
        add_action("do_ketou","ketou");
        add_action("do_move","move");
}

int do_pick(string arg)
{
        object me,letter;
        
        me=this_player();

	if (!arg || arg=="")
		return notify_fail("pick <���>\n");

        if( arg=="letter" ) 
        {
                message_vision(
		"$N�ߵ��Ǹ����ӵ�����֮ǰ�����ְ���ʰ��������\n", me);
                letter = new(__DIR__"obj/letter");
                letter->move(me);
		return 1;
        }

        return notify_fail("��Ҫ��ʲô��\n");
}


int do_ketou()
{
        object me,book;

        me = this_player();

        message_vision("$N�ϵع�������������ǰ��ͷ��\n", me);
        
        if ((int)me->query("gin")<=50) 
        { 
                tell_object(me,"��̫���ˣ���Ϣһ�°ɣ�\n");
                return 1;
        }

        if ( random(20) == 11 )
        {
                book=new(__DIR__"obj/skinbook");
                book->move(me);
                tell_object(me, "ͻȻ���û���һ�����£�¶��һ����Ƥ��!\n");
        }

        me->receive_damage("gin", 50);

        return 1;

}


int do_move(string arg)
{
        
        if( !arg || arg=="" )
		return notify_fail("move <���>\n");

        if(arg=="����")
	{
                if(this_player()->query_skill("qiankun-danuoyi",1)>=10)
        	{
                	message_vision(
"$N����Ǭ����Ų���ķ���ʯ�ű���������,�����ؿ��ˡ�\n", this_player());
                	set("exits/out", __DIR__"midao");

	                remove_call_out("close");
        	        call_out("close", 5, this_object());

	                return 1;
		}

		return notify_fail("���Ǭ����Ų�ƹ���������\n");

	}
	return notify_fail("��Ҫ�ƶ�ʲô��\n");
}

void close(object room)
{
        message("vision","ʯͷ�ƻ�ԭ�ء�\n", room);
        room->delete("exits/out");
}
