inherit ROOM;

void create()
{
   set("short", "�·");
	set("long", @LONG
������ʯ��ܬ�Ļ�԰�·�ϣ�ֻ�����ߴ����·�������²�̦
�������������㿴����βɭɭ������ϸϸ��ͨ��ů��鿡���������
һ��С�š�����ͨ��԰��С�š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "northwest" :__DIR__"bridge2",
       "northeast" :__DIR__"moon4",
       "south" :__DIR__"moondoor",

]));

	setup();
	replace_program(ROOM);
}
