// Room: /d/village/lakebottom1.c

inherit ROOM;

void create()
{
	set("short", "ˮ���Ҷ�");
	set("long", @LONG
����Ҷ���ȫ���Ǳ�������ɫ������ף������Ǳ�����������ȴ��
֪��ô����������֡��������¼��ͣ�������Ϯ������������վ��Ƭ�̡�
���������泤�ŷ��������ֲ����Դ���ڿ�ȥ�ǳ��������ղŽ�����
������ڴ���Ѹ�ٵؽ���һ�㱡������ֵ���ˮѹ��û�а���ѹ�ơ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "westup" : __DIR__"lakebottom2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
