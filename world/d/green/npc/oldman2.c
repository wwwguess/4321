inherit NPC;
 
void cancel_give();
void start_give();
void set_flag();
 
void create()
{
        seteuid(getuid());
        set_name("�峤", ({"elder", "oldman", "man"}));
        set("long", @TEXT
TEXT
        );
        set("gender","����");
        set("age",95);
	set("max_gin",100);
	set("max_kee",200);
	set("max_sen",100);
        set("combat_exp",500);
        set("attitude","friendly");
        set("chat_chance",10);
        set("inquiry", ([
        "����" : ({
            "��...... ����˵�Ǹ��ӹ�Ĺ������������?\n",
            "Ӧ��������, �����е���·����...\n",
            "���͸�һ����������, ������˵���ô������������.\n",
            "�������ﲻ��... \n",
            "��Ҫ������? ����˵�������Ծƶ���, ��Ҳ��֪��������.\n",
            (: command, "shrug" :),
            (: set_flag :),
            "������........\n",
            }),
        ]) );
        set("chat_msg", ({
                (: cancel_give :),
                (: start_give :),
        }) );
        setup();
        carry_object("/obj/cloth")->wear();
}
 
void relay_say(object me, string str)
{
        if ((str == "��������")) {
                command("hehe");
                command("say ��ѽ.. ���������... ");
                command("laugh "+(string)me->query("id"));
                return;
        }
}
 
void start_give()
{
        command("say ��֮����.....");
}
 
void cancel_give()
{
        command("sigh");
}
 
void set_flag()
{
    object ob;
 
    if( !objectp(ob = query_temp("last_asker")) ) return;
    ob->set_temp("elder_info",1);
	return;
}
