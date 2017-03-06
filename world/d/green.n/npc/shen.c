// Mon  08-21-95
 
inherit NPC;
 
string ask_jade();
string ask_drug();
 
void create()
{
        seteuid(getuid());
        set_name("������",({"shen wen-nien","shen"}));
        set("title","��������ƹ�");
        set("gender", "����" );
        set("age",45);
        set("combat_exp",30);
        set("attitude", "friendly" );
        set_temp("apply/dodge",5);
        set_temp("apply/attack",3);
        set("inquiry", ([
        "����" : (: ask_jade :),
        "�ɺ�ҩ" : (: ask_drug :),
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver",1);
}
 
void init()
{
        add_action("list_item","list");
        add_action("buy_item","buy");
}
 
int list_item()
{
        write("�㿴��:\n");
        write("������һ��ڤֽ�������, ��� 10 ��Ǯ. ǽ�Ϲ���������ɨ��,\n");
        write("ÿ�� 50 ��Ǯ. ��̨�ϰ�\��һ��ľ��, ����д��:\n");
        write("�ײ�: ʱ��. û�����Ķ�����һ���ƹ��.\n");
        return 1;
}
 
int buy_item(string str)
{
        command("shake");
        command("say �Ҳ���������İ����!");
        return 1;
}
 
string ask_jade()
{
    if(this_player()->query_temp("drunk")) {
        command("whisper "+(string)this_player()->query("id")+
        " ��... �������ȥ, ���������, ����ʮ�������Ӷ������������.\n");
    }
    return "������������.... \n";
}
 
string ask_drug()
{
    if(this_player()->query_temp("drug")) {
        command("whisper "+(string)this_player()->query("id")+
        " һ������, ��Ҫ�����ּۻ���.\n");
    }
    return "��......\n";
}
 
int accept_object(object who, object ob)
{
    object item;
    if ((ob->value() == 1500) && (who->query_temp("drunk"))) {
    return 1;
    }
    if (ob->value() == 100) {
    item = new("/obj/slumber_drug");
    item->move(this_object());
    command("give drug to "+(string)who->query("id"));
    return 1;
    }
    return 0;
}
 
