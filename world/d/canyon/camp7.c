// ROOM:__DIR__"camp7"

inherit ROOM;
void create()
{
        set("short","����Ӫ��");
	set("long",@LONG                                   
����������������ܵľ���������˲������ţ���ǰ��ľ�Ӫ����
��ͬ����Ƥ���ھ��Σ��������ںڸ���ʯ���ϣ���Ϊ��Ե˫����ͼ������
�������������ȣ�����������ë��Ƥ�̳�����ȷʵ�и���Ӫ�ʵ�ζ����
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
		"east" : __DIR__"camp8",
		"west" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/vice_general" : 1,
	]) );
	
	setup();
	
}

int valid_leave(object me,string dir)
{
	if ( dir=="east" && !(string)me->query("marks/��Ӫ") )
        return notify_fail("�㻹û������\����ม�\n");
	
	return ::valid_leave(me,dir);
}
