// oldwoman.cage/npc/oldwoman.c
inherit NPC;
void create()
{
        set_name("������", ({ "old woman", "woman" }) );
        set("gender", "Ů��" );
        set("age", 63);
        set("long", "һ��������˪֮ɫ�������š�\n");
        set("shen_type", 1);
        set("combat_exp", 150);
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        set("inquiry", ([
                "����" : "���̾���ɽ�ϣ������߾��ǣ��� ~ ~���ǰ�������滵͸�ˡ�",
             
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "���������ĵ�˵����Ҳ��֪��������ʲôʱ�������\n",
                "������������������ú��������������������˺�������ȥ���๤��\n",
                "�����Ŵ����������������ӣ���������ˡ�\n",
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("coin", 100);
}
