// servant.c

inherit NPC;

void create()
{
	set_name("����", ({ "servant" }) );
	set("gender", "����");
	set("age", 34);
	set("long", "����˿�����ʮ�ֺͰ����ף������������ǻ��书\���ˡ�\n");

	set("attitude", "friendly");
	set("combat_exp", 100);

	set("str", 25);
	set("cor", 23);
	set("cps", 23);
	set("con", 27);

	setup();
}
