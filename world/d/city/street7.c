// Room: /d/city/street7.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
��ʦ�������ߺͱ������Ҫ�ֵ������������ｻ�棬������Ļ�
�������������������ַǷ�������ĻʼҼ�̳�����������壬������
�����������ɫ�ı����š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "d/city/street8",
  "west" : "d/city/street15",
  "north" : "d/city/street16",
  "south" : "d/city/jitan",]));

	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
