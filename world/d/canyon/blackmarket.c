// ROOM:__DIR__"blackmarket"

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG                                   
���������Կ���ǽ�Ϲ����˸�ʽ������������������������Ǵ��
�����ĵط�����ǽ��д�˸�ŵ��ġ������֡�
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
		"east" : __DIR__"canyon4",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/seller" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
