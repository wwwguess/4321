
inherit ROOM;

void create()
{
	set("short","��");
	set("long", @LONG
    һ����ƥ�����Ĵ�. ��Ȼ��̫�ÿ�,����ͦ��ʵ. 
��������ǰ��һ˦��, ����͵õõ�������.
LONG
	);

	setup();
}

void init()
{
	add_action("do_say","say");
}

int do_say(string arg)
{

	if(arg=="֥�鿪��")
	{
		write("�����ǰһ�������Ŵ��ˡ�\n");
               	set("exits/out", VOID_OB);
                remove_call_out("close");
       	        call_out("close", 5, this_object());
                return 1;
	}
	return 0;

}

void close(object room)
{
        message("vision","���ϴ���һ����죺�ſ��ˣ���ô����ȥ��\n", room);
        room->delete("exits/out");
}

int valid_leave(object me, string dir)
{
	this_object()->delete("youren");
	return ::valid_leave(me,dir);
}

