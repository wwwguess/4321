// fisher.c

inherit NPC;

void create()
{
	set_name("���", ({ "fisher" }) );
	set("gender", "����" );
	set("age", 35);
       	set("long", @LONG 
һ����׳�ĺ��ӣ�ͷ�����ң��������¡�ż��̧ͷһ��������
�о����ʢ�����п����ǽ������ˡ�
LONG
);
	set("combat_exp", 20000);
	set("attitude", "friendly");
        set("chat_chance", 2);
       	set("chat_msg", ({
"����ֹ��ţ���֪��ˮ���ֳ��˼����ˡ�\n",
       }) );

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
"���ֵ�ȥɱ����ˮ�֣�������ʲôӢ�ۣ���\n",
        }) );
	set("inquiry", ([
		"��" : "��������ѧ�Ĺ���������ׯ����ˣ���֪����",
	]) );

	set_skill("parry", 30);
	set_skill("dodge", 70);
	set_skill("unarmed", 120);
	set_skill("throwing", 150);
       	set_skill("stormdance", 45);

        map_skill("dodge", "stormdance");
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 0);

	setup();
	carry_object("/obj/cloth")->wear();

}
