inherit NPC;

void create()
{
     set_name("�ϵ�ʿ", ({"old taoist", "taoist"}) );
     set("gender", "����");
     set("age", 46);
     set("class", "taoist");
     set("long", "һλ�Ĵ����ε��ϵ�ʿ, �����ڹ��Ĺ۹ҵ��С�\n"
                 "����������ɣ������, �ƺ���Ҳ�Ǿ����������Ĵ����ˡ�\n");
     set("attitude", "peaceful");
     set("combat_exp", 2500);

     set_skill("dodge", 10);
     set_skill("parry", 15);
     set_skill("whip", 25);

     setup();

     carry_object(__DIR__"obj/whip")->wield();
     carry_object(__DIR__"obj/old_robe")->wear();
     add_money("silver", 5);
}

int accept_fight(object ob)
{
     command("say �����ٷ� ! ƶ��������˥, ����ʩ���Ķ��֡�\n");
     return 0;
}
