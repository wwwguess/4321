// guifang
// yuer 

inherit ROOM;

int do_push(string arg);

void create()
{
	set("short", "�뷿");
	set("long", @LONG
	�������С��Ĺ뷿��һ���������������һ����齷���ǽ�ǣ�����ϸɴ��
   ����ǽ���Ϲ��˺�Щ������
LONG
	);

	set("exits", ([
		"south" : __DIR__"houyuan",
	]));
	
        set("no_clean_up", 0);
        set("valid_startroom", 1);

        setup();
	
}
void init()
{
       
	add_action("do_push", "push");
}

int do_push(string arg)
{

        if( !arg || arg=="" ) return 0;

        if( arg=="���")
        {
                write("ֻ�����·��������졣\n");
		message("vision", "���������и�����\n", this_player());
                set("exits/down", __DIR__"midao");

                remove_call_out("close");
                call_out("close", 5, this_object());

                return 1;
        }
}

void close(object room)
{
        message("vision","����ƻ�ԭ�ء�\n", room);
        room->delete("exits/down");
}




