
inherit NPC;

inherit F_MASTER;

void create()
{
        set_name("������",({"master chairman","master","chairman","chang"}));
	set("gender", "����" );
	set("age", 54);
        set("combat_exp",200000);
        set("int",10);
        set("long",@LONG
���Ǹ���ѧ��ŵĽ��ڣ�ͬѧ�Ƕ��ܾ�������
LONG
);
      set("chat_chance",2);
      set("chat_msg",({
        (: random_move :),
        }));
      set("attitude","peaceful");
      create_family("�Ӻ���",5,"У��");
      set_skill("literate",200);
      set_skill("sword",120);
      setup();
      carry_object(__DIR__"obj/chunqiu_pen")->wield();
}
void init()
{
      ::init();
      this_player()->set("marks/�Ӻ���ѧ",1);
}
void attempt_apprentice(object ob)
{
     if((int)ob->query_skill("literate",1) < 5 )
     {
             command("say ��Ӧ�ö�ѧ���Ļ������ִ������Ҫ֪ʶ����");
             command("? "+ob->query("id"));
             return;
        }
     command("recruit "+ob->query("id"));
}
