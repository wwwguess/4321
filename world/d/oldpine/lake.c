// Room: /d/oldpine/lake.c

inherit ROOM;

void create()
{
	set("short", "ˮ̶");
	set("long", @LONG
��������վ��һ������׵�ˮ̶���ϣ���̶�ײ�ʱ������ð����
��ɢ����һ�ɹ������ζ��ˮ̶�߳����˻�ɫҶ�ӵĹֲݣ����ܶ��͵�
ɽ�ڽ���ֱ����̧ͷֻ��һ����Բ�ε���գ�Ψһ�ĳ�·���ֻ������
ɽȪ����ˮ̶��ȱ�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/oldpine/riverbank1",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/oldpine/npc/serpent" : 5,
]));
	set("resource/water", 1);
	setup();
	replace_program(ROOM);
}
