// ROOM:__DIR__"canyon2"

inherit ROOM;
void create()
{
        set("short","����С·");
	set("long",@LONG                                   
������������µĻ������Ǻ���һ�㣬�ɼ�������������·���˱�
���࣬�򱱼��ǰ���β������һֱͨ�����չؿڣ����������ǻ����ɽ��
�����ƺ���Ϊ�Ͼ���
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
        	"northeast" : __DIR__"canyon1",
        	"south" : __DIR__"canyon3",
	]) ); //eof(exits)
	
	setup();
	
	replace_program(ROOM);
} //EOF
