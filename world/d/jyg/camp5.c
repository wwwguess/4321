// ROOM:__DIR__"camp5"

inherit ROOM;
void create()
{
        set("short","�ӳ�Ӫ��");
	set("long",@LONG                                   
�����Ƕӳ���Ӫ�ʣ������Ծɺ�С��Ӫ��һ���Ŀտ�����Ӫ�ʵĲ�
�ϵ��Ǳ�С��Ӫ�ʺö��ˣ�����������ľ��.�Ƕӳ�������ĵط���
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"south" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/duizhang" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
