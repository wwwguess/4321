// ROOM:__DIR__"camp5"

inherit ROOM;
void create()
{
        set("short","С�ӳ�Ӫ��");
	set("long",@LONG                                   
�����С�ӳ���Ӫ�ʣ������Ծɺ�С��Ӫ��һ���Ŀտ�����Ӫ�ʵĲ�
�ϵ��Ǳ�С��Ӫ�ʺö��ˣ��������������Σ���������С�ӳ�͵��ʱ��Ϣ
�ĵط���
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"south" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/leader1" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
