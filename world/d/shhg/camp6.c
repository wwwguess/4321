// ROOM:__DIR__"camp6"

inherit ROOM;
void create()
{
        set("short","С�ӳ�Ӫ��");
	set("long",@LONG                                   
���Ʊ��ߵ�Ӫ�ʣ��տյ����ģ�������һ��Ҳ�����Ǿ�Ӫ��һ������
�ĸо�Ҳû�У�����Ҳ�����Ѽ��׵����Σ���λ�ӳ���ƽ��С��û������
�ǲ������Խ�������ģ��򶫱��Ǹ���Ӫ�ʣ���û�о����������ǲ���
����ġ�
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/captain" : 1,
		__DIR__"npc/leader2" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
