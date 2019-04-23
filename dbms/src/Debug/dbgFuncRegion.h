#pragma once

#include <Debug/DBGInvoker.h>
#include <Parsers/IAST.h>

namespace DB
{

class Context;

// Region manipulation tools

// Inject a region and optionally map it to a table.
// Usage:
//   ./storages-client.sh "DBGInvoke put_region(region_id, start, end, database_name, table_name)"
void dbgFuncPutRegion(Context & context, const ASTs & args, DBGInvoker::Printer output);

// Simulate a region snapshot raft command
// Usage:
//   ./storages-client.sh "DBGInvoke region_snapshot(region_id, start, end, database_name, table_name)"
void dbgFuncRegionSnapshot(Context & context, const ASTs & args, DBGInvoker::Printer output);

// Dump region-partition relationship
// Usage:
//   ./storage-client.sh "DBGInvoke dump_region()"
void dbgFuncDumpRegion(Context & context, const ASTs & args, DBGInvoker::Printer output);

// Remove region's data from partition
// Usage:
//   ./storage-client.sh "DBGInvoke rm_region_data(region_id)"
void dbgFuncRegionRmData(Context & context, const ASTs & args, DBGInvoker::Printer output);

void dbgFuncDumpAllRegion(Context & context, const ASTs & args, DBGInvoker::Printer output);

} // namespace DB